# 🛒 Campus Second-Hand Marketplace

A desktop GUI application developed in **C++** using **Qt Widgets** that enables college students to buy and sell second-hand items within their campus. The application provides a secure and organized marketplace for books, electronics, lab coats, gadgets, and more.

---

## 📌 Project Overview

Campus Second-Hand Marketplace is designed to simplify the buying and selling of used items among students. Users can browse available listings, search products, negotiate prices, add products to a wishlist, and sell their own items through an intuitive desktop interface.

The project demonstrates strong Object-Oriented Programming (OOP) concepts while providing a clean and user-friendly graphical interface.

---

## ✨ Features

### 👤 Buyer
- Browse all available listings
- Search items by name
- View complete product details
- Buy available items
- Negotiate item prices
- Add items to wishlist
- Remove items from wishlist

### 🛍 Seller
- List new products for sale
- Add Books, Electronics, or Clothing
- Dynamic listing updates

### 💡 Marketplace
- Product categorization
- Interactive GUI
- Real-time listing updates
- Sold item management
- Wishlist management

---

## 🏗 Project Structure

```
CampusSecondHandMarketplace/
│
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
│
├── Product.h
├── Book.h
├── Electronics.h
├── Clothing.h
│
├── Listing.h
├── User.h
├── Buyer.h
├── Seller.h
├── Transaction.h
│
├── CMakeLists.txt
└── README.md
```

---

## ⚙ Technologies Used

- C++
- Qt 6 (Qt Widgets)
- CMake
- Object-Oriented Programming (OOP)

---

## 🎯 OOP Concepts Implemented

### ✅ Abstraction
- `Product`
- `User`

Both are abstract base classes using pure virtual functions.

### ✅ Inheritance

```
Product
│
├── Book
├── Electronics
└── Clothing

User
│
├── Buyer
└── Seller
```

### ✅ Polymorphism

Each product overrides

```cpp
getDetails()
```

to display category-specific information.

### ✅ Encapsulation

Private data members accessed using getters and setters.

### ✅ Composition

A `Listing` object contains a `Product`.

### ✅ Operator Overloading

Comparison operators implemented for products based on price.

---

## 📦 Supported Categories

- 📚 Books
- 💻 Electronics
- 👕 Clothing

---

## 🔄 Application Workflow

```
Launch Application
        │
        ▼
Browse Listings
        │
        ▼
Search Products
        │
        ▼
Select Item
        │
        ├──────────────┐
        ▼              ▼
Buy Item       Add to Wishlist
        │
        ▼
Transaction Complete
```

---

## 🚀 Current Features

- ✔ Browse Listings
- ✔ Search Functionality
- ✔ Buy Items
- ✔ Wishlist Management
- ✔ Sell New Items
- ✔ Price Negotiation
- ✔ Dynamic GUI Updates

---

## 🔮 Future Enhancements

- User Login & Authentication
- SQLite Database Integration
- Product Images
- Chat Between Buyer & Seller
- Ratings & Reviews
- Order History
- Persistent Data Storage
- Admin Dashboard

---

## 📚 Learning Outcomes

This project helped in understanding:

- Qt Widgets Programming
- Event-driven GUI Development
- OOP Design Principles
- Dynamic Memory Management
- C++ STL
- GUI Layout Management
- Signal & Slot Mechanism

---

## 🛠 Build Instructions

### Clone Repository

```bash
git clone https://github.com/nutanshinde1/CampusSecondHandMarketplace.git
```

### Open Project

Open the project using **Qt Creator**.

### Build

- Configure Kit
- Build Project
- Run

---

## 👨‍💻 Author

**Nutan Shinde**

---

## 📄 License

This project is developed for educational purposes.
