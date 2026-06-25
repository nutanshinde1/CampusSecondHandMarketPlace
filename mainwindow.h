#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Qt Widgets
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

// Models
#include "Listing.h"
#include "Book.h"
#include "Electronics.h"
#include "Clothing.h"

#include <vector>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // 🔹 UI Components
    QListWidget *listingList;
    QLabel *itemNameLabel;
    QLabel *priceLabel;
    QLabel *detailsLabel;

    QPushButton *buyBtn;
    QPushButton *wishlistBtn;
    QPushButton *negotiateBtn;

    QLineEdit *searchBox;
    QPushButton *sellBtn;

    QListWidget *wishlistList;
    QPushButton *removeWishlistBtn;

    // 🔹 Data
    vector<Listing*> listings;
    vector<Listing*> wishlist;
    vector<Listing*> filteredListings;

    // 🔹 Functions
    void setupUI();
    void loadDummyData();
    //void displayDetails(Listing* listing);

private slots:
    void onItemClicked(QListWidgetItem *item);
    void onBuyNowClicked();
    void onWishlistClicked();
    void onNegotiateClicked();
    void onSearchTextChanged(const QString &text);
    void onSellItemClicked();

    void onRemoveWishlistClicked();
};

#endif