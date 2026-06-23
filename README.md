# Smart Email Management System

A console-based Smart Email Management System developed using C and SQLite. This application enables users to compose, organize, search, and manage emails through an interactive menu-driven interface while maintaining persistent storage using SQLite.

---

## Features

- Email Composition
- Inbox Management
- Sent Emails
- Draft Emails
- Trash Management
- Starred Emails
- Search Functionality
- Email Categories
- Email Priorities
- Analytics Dashboard
- SQLite Database Integration
- Persistent Storage
- Modular Architecture
- Demo Data Generation

---

## Technologies Used

### Programming Language
- C

### Database
- SQLite

### Concepts
- Linked Lists
- Dynamic Memory Allocation
- Modular Programming
- SQL Queries
- File Handling

### Tools
- GCC Compiler
- SQLite3
- Git
- GitHub
- Visual Studio Code

---

## Project Structure

```text
Smart-Email-Management-System/
│
├── include/
│   ├── email.h
│   ├── database.h
│   └── search.h
│
├── src/
│   ├── main.c
│   ├── email.c
│   ├── database.c
│   └── search.c
│
├── sqlite/
│   ├── sqlite3.c
│   └── sqlite3.h
│
├── database/
│   └── emails.db
│
├── screenshots/
│   ├── main-menu.png
│   ├── inbox.png
│   ├── search.png
│   └── dashboard.png
│
├── README.md
├── .gitignore
└── LICENSE
```

---

## Installation and Setup

### 1. Clone the Repository

```bash
git clone https://github.com/oviya-lakshmi/Smart-Email-Management-System.git
```

### 2. Navigate to the Project Folder

```bash
cd Smart-Email-Management-System
```

### 3. Compile the Project

```bash
gcc src/main.c src/email.c src/database.c sqlite/sqlite3.c -Iinclude -Isqlite -o EmailClient.exe
```

### 4. Run the Application

```bash
EmailClient.exe
```

---

## Application Features

### Email Operations

- Compose Email
- View Inbox
- View Sent Emails
- View Draft Emails
- Move Emails to Trash
- Restore Deleted Emails
- Star Important Emails

### Search and Organization

- Search Emails by Subject
- Search Emails by Content
- Categorize Emails
- Assign Priority Levels
- View Starred Emails

### Analytics Dashboard

- Folder-wise Email Statistics
- Email Count Overview
- Activity Summary

### Database Operations

- Persistent SQLite Storage
- Reset Database
- Load Demo Data

---

## Sample Menu

```text
=========================================
 SMART EMAIL MANAGEMENT SYSTEM v2.0
=========================================

1. Compose Email
2. View Inbox
3. View Sent Emails
4. View Drafts
5. View Trash
6. Star Email
7. View Starred Emails
8. Search Emails
9. Delete Email
10. Restore Email
11. Analytics Dashboard
12. Reset Database
13. Load Demo Data
14. Exit
```

---

## Learning Outcomes

Through this project, the following concepts were implemented and explored:

- SQLite Database Integration in C
- Linked List Data Structures
- Dynamic Memory Management
- Modular Software Design
- Search Functionality
- Data Persistence
- Console-Based Application Development
- Database Query Processing

---

## Future Enhancements

- Contact Management System
- Email Scheduling
- Attachment Support
- Spam Detection
- User Authentication
- Backup and Restore Functionality
- GUI-Based Interface using GTK
- Multi-User Support

---

## Author

**Oviya Lakshmi**

GitHub: https://github.com/oviya-lakshmi

---

## License

This project is developed for educational and learning purposes.
