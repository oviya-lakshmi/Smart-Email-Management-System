# Smart Email Management System

A console-based Smart Email Management System developed using C and SQLite. This application allows users to compose emails, manage inbox and sent folders, organize drafts, star important emails, search messages efficiently, and store data persistently using SQLite.

## Features

* Email Composition
* Inbox Management
* Sent Emails
* Draft Emails
* Trash Management
* Starred Emails
* Search Functionality
* Email Categories
* Email Priorities
* Analytics Dashboard
* SQLite Database Integration
* Persistent Storage
* Modular Architecture
* Demo Data Generation

## Technologies Used

### Programming Language

* C

### Database

* SQLite

### Concepts

* Linked Lists
* Dynamic Memory Allocation
* Modular Programming
* SQL Queries
* File Handling

### Tools

* GCC Compiler
* SQLite3
* Git
* GitHub
* Visual Studio Code

## Project Structure

Smart-Email-Management-System/

├── include/
│ ├── email.h
│ ├── database.h
│ └── search.h
│
├── src/
│ ├── main.c
│ ├── email.c
│ ├── database.c
│ └── search.c
│
├── sqlite/
│ ├── sqlite3.c
│ └── sqlite3.h
│
├── database/
│ └── emails.db
│
├── README.md
├── .gitignore
└── LICENSE

## Installation and Setup

### 1. Clone the Repository

```bash
git clone https://github.com/oviya-lakshmi/Smart-Email-Management-System.git
```

### 2. Navigate to Project Folder

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

## Application Features

### Email Operations

* Compose Email
* View Inbox
* View Sent Emails
* View Draft Emails
* Delete Emails
* Restore Emails
* Star Important Emails

### Search and Organization

* Search Emails by Subject
* Search Emails by Content
* Categorize Emails
* Assign Priorities

### Analytics

* View Email Statistics
* Folder-wise Email Distribution

### Database Operations

* Persistent SQLite Storage
* Reset Database
* Load Demo Data

## Learning Outcomes

* Database Integration using SQLite
* Linked List Implementation in C
* Modular Software Design
* Search Algorithms
* Data Persistence
* Console Application Development

## Future Enhancements

* Contact Management
* Email Scheduling
* Attachment Support
* Spam Detection
* User Authentication
* Backup and Restore System
* GUI-Based Interface

## Author

Oviya Lakshmi

GitHub:
https://github.com/oviya-lakshmi

## License

This project is developed for educational and learning purposes.
