#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QFont>
#include <QInputDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    loadDummyData();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    QWidget *central = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // 🔝 Title
    QLabel *title = new QLabel("Campus Second-Hand Marketplace");
    title->setStyleSheet("font-size: 18px; font-weight: bold; color: white;");

    sellBtn = new QPushButton("+ Sell Item");

    QHBoxLayout *topBar = new QHBoxLayout;
    topBar->addWidget(title);
    topBar->addStretch();
    topBar->addWidget(sellBtn);


    // 🔍 Search Box
    searchBox = new QLineEdit;
    searchBox->setPlaceholderText("Search items...");

    // 📦 Left Panel (Listings)
    listingList = new QListWidget;

    // 📄 Right Panel (Details)

    itemNameLabel = new QLabel("Select an item");
    priceLabel = new QLabel("₹0");
    detailsLabel = new QLabel("");

    buyBtn = new QPushButton("Buy Now");
    wishlistBtn = new QPushButton("Add to Wishlist");
    negotiateBtn = new QPushButton("Negotiate");

    // ⭐ Wishlist UI
    wishlistList = new QListWidget;
    removeWishlistBtn = new QPushButton("Remove Selected");

    // 🔷 Layout
    QVBoxLayout *rightLayout = new QVBoxLayout;

    rightLayout->addWidget(itemNameLabel);
    rightLayout->addWidget(priceLabel);
    rightLayout->addWidget(detailsLabel);

    rightLayout->addWidget(buyBtn);
    rightLayout->addWidget(wishlistBtn);
    rightLayout->addWidget(negotiateBtn);

    // 🔷 Wishlist Section Title
    QLabel *wishlistTitle = new QLabel("Wishlist");
    wishlistTitle->setStyleSheet("font-weight: bold; margin-top: 10px;");
    rightLayout->addWidget(wishlistTitle);

    // 🔷 Wishlist List
    rightLayout->addWidget(wishlistList);
    rightLayout->addWidget(removeWishlistBtn);

    // 🔷 Create Right Panel Widget (IMPORTANT FIX)
    QWidget *rightPanel = new QWidget;
    rightPanel->setLayout(rightLayout);


    // 🔄 Main Split
    QHBoxLayout *contentLayout = new QHBoxLayout;
    contentLayout->addWidget(listingList, 2);
    contentLayout->addWidget(rightPanel, 1);

    // 🧱 Combine Layout
    mainLayout->addLayout(topBar);
    mainLayout->addWidget(searchBox);
    mainLayout->addLayout(contentLayout);

    central->setLayout(mainLayout);
    setCentralWidget(central);

    // 🎨 Dark Theme
    this->setStyleSheet(R"(
        QWidget {
            background-color: #0d0c1d;
            color: #e0dfff;
        }

        QPushButton {
            background-color: #6c5ce7;
            border-radius: 8px;
            padding: 6px;
        }

        QPushButton:hover {
            background-color: #a29bfe;
        }

        QLineEdit {
            background-color: #1a1833;
            padding: 6px;
            border-radius: 6px;
        }
    )");

    // 🔗 Connect click
    connect(listingList, &QListWidget::itemClicked,
            this, &MainWindow::onItemClicked);

    connect(buyBtn, &QPushButton::clicked,
            this, &MainWindow::onBuyNowClicked);

    connect(wishlistBtn, &QPushButton::clicked,
            this, &MainWindow::onWishlistClicked);

    connect(negotiateBtn, &QPushButton::clicked,
            this, &MainWindow::onNegotiateClicked);

    connect(searchBox, &QLineEdit::textChanged,
            this, &MainWindow::onSearchTextChanged);

    connect(sellBtn, &QPushButton::clicked,
            this, &MainWindow::onSellItemClicked);


    connect(removeWishlistBtn, &QPushButton::clicked,
            this, &MainWindow::onRemoveWishlistClicked);
}

// 🔹 Dummy Data
void MainWindow::loadDummyData()
{
    // 🔹 Create Products
    Product* b1 = new Book("Data Structures", 180, "Tanenbaum", "3rd");
    Product* e1 = new Electronics("Scientific Calculator", 350, "Casio", "Good");
    Product* c1 = new Clothing("White Lab Coat", 120, "42", "Generic");
    Product* b2 = new Book("DBMS Concepts", 220, "Navathe", "6th");

    // 🔹 Create Listings
    listings.push_back(new Listing(b1, "Rahul"));
    listings.push_back(new Listing(e1, "Priya"));
    listings.push_back(new Listing(c1, "Rahul"));
    listings.push_back(new Listing(b2, "Arjun"));

    // 🔹 Add to UI list
    for (int i = 0; i < listings.size(); i++) {
        listingList->addItem(QString::fromStdString(listings[i]->getSummary()));
    }
}

// 🔹 Item Click Handler
void MainWindow::onItemClicked(QListWidgetItem *item)
{
    int index = listingList->row(item);

    Listing* selected = nullptr;

    // If search is active
    if (!filteredListings.empty()) {
        if (index >= 0 && index < filteredListings.size()) {
            selected = filteredListings[index];
        }
    }
    else {
        if (index >= 0 && index < listings.size()) {
            selected = listings[index];
        }
    }

    if (selected) {
        itemNameLabel->setText(QString::fromStdString(selected->getProduct()->getName()));
        priceLabel->setText("₹" + QString::number(selected->getProduct()->getPrice()));
        detailsLabel->setText(QString::fromStdString(selected->getProduct()->getDetails()));
    }
}
// Buy
void MainWindow::onBuyNowClicked()
{
    int index = listingList->currentRow();

    if (index >= 0 && index < listings.size()) {
        Listing* selected = listings[index];

        if (selected->isAvailable()) {
            selected->markSold();

            listingList->item(index)->setText(
                QString::fromStdString(selected->getSummary()) + " (SOLD)"
                );

            itemNameLabel->setText("Item Sold");
            priceLabel->setText("");
            detailsLabel->setText("This item has been purchased.");
        }
    }
}



//Negotiate
void MainWindow::onNegotiateClicked()
{
    int index = listingList->currentRow();

    if (index >= 0 && index < listings.size()) {
        Listing* selected = listings[index];

        double originalPrice = selected->getProduct()->getPrice();

        bool ok;
        double offer = QInputDialog::getDouble(
            this,
            "Negotiate Price",
            "Enter your offer:",
            0,
            0,
            originalPrice,
            2,
            &ok
            );

        if (ok) {
            if (offer >= 0.4 * originalPrice) {
                itemNameLabel->setText("Offer Accepted");
                priceLabel->setText("Final Price: ₹" + QString::number(offer));
                detailsLabel->setText("Seller accepted your offer!");
            } else {
                itemNameLabel->setText("Offer Rejected");
                detailsLabel->setText("Offer too low (must be ≥ 40%)");
            }
        }
    }
}

//Search
void MainWindow::onSearchTextChanged(const QString &text)
{
    listingList->clear();
    filteredListings.clear();

    for (int i = 0; i < listings.size(); i++) {
        QString name = QString::fromStdString(listings[i]->getProduct()->getName());

        if (name.toLower().contains(text.toLower())) {
            filteredListings.push_back(listings[i]);

            listingList->addItem(
                name + " - ₹" +
                QString::number(listings[i]->getProduct()->getPrice())
                );
        }
    }
}

void MainWindow::onSellItemClicked()
{
    bool ok;

    QString name = QInputDialog::getText(this, "Sell Item", "Enter item name:", QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    double price = QInputDialog::getDouble(this, "Sell Item", "Enter price:", 0, 0, 100000, 2, &ok);
    if (!ok) return;

    QString category = QInputDialog::getText(this, "Sell Item", "Enter category (Book/Electronics/Clothing):", QLineEdit::Normal, "", &ok);
    if (!ok || category.isEmpty()) return;

    Product* newProduct = nullptr;

    if (category.toLower() == "book") {
        QString author = QInputDialog::getText(this, "Book", "Author:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        QString edition = QInputDialog::getText(this, "Book", "Edition:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        newProduct = new Book(name.toStdString(), price, author.toStdString(), edition.toStdString());
    }
    else if (category.toLower() == "electronics") {
        QString brand = QInputDialog::getText(this, "Electronics", "Brand:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        QString condition = QInputDialog::getText(this, "Electronics", "Condition:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        newProduct = new Electronics(name.toStdString(), price, brand.toStdString(), condition.toStdString());
    }
    else if (category.toLower() == "clothing") {
        QString size = QInputDialog::getText(this, "Clothing", "Size:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        QString brand = QInputDialog::getText(this, "Clothing", "Brand:", QLineEdit::Normal, "", &ok);
        if (!ok) return;

        newProduct = new Clothing(name.toStdString(), price, size.toStdString(), brand.toStdString());
    }
    else {
        QMessageBox::warning(this, "Error", "Invalid category!");
        return;
    }

    Listing* newListing = new Listing(newProduct, "You");
    listings.push_back(newListing);

    listingList->addItem(QString::fromStdString(newListing->getSummary()));

    QMessageBox::information(this, "Success", "Item listed successfully!");
}

void MainWindow::onWishlistClicked()
{
    int index = listingList->currentRow();

    Listing* selected = nullptr;

    if (!filteredListings.empty()) {
        selected = filteredListings[index];
    } else {
        selected = listings[index];
    }

    if (selected) {
        wishlist.push_back(selected);

        wishlistList->addItem(
            QString::fromStdString(selected->getProduct()->getName())
            );

        itemNameLabel->setText("Added to Wishlist");
        detailsLabel->setText("Item added successfully.");
    }
}

void MainWindow::onRemoveWishlistClicked()
{
    int index = wishlistList->currentRow();

    if (index >= 0 && index < wishlist.size()) {
        wishlist.erase(wishlist.begin() + index);
        delete wishlistList->takeItem(index);
    }
}