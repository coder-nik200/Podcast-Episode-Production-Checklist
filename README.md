# Podcast Episode Production Checklist

A console-based C++ application designed to manage podcast episode information and track the production checklist for each episode.

## About the Project

The **Podcast Episode Production Checklist** is a minor project developed for **CAP455: Object-Oriented Programming using C++**.

The application helps users maintain basic podcast episode records and view the production tasks associated with each episode. It uses object-oriented programming concepts such as classes, objects, encapsulation, static members, friend functions, pointers, references, and arrays of objects.

This project is developed in multiple phases, with the current implementation focusing on **CA1: Design and Create**.

## Features

- Add new podcast episodes.
- View all registered episodes.
- View complete details of a selected episode.
- View the production checklist for an episode.
- Display the total number of registered episodes.
- Prevent duplicate episode IDs.
- Validate episode IDs and duration.
- Validate basic recording date format.
- Handle invalid numeric input.
- Store up to 30 episodes during program execution.

## Production Checklist

Each episode contains the following eight predefined production tasks:

1. Topic Research
2. Script Preparation
3. Guest Confirmation
4. Recording Completed
5. Audio Editing
6. Thumbnail Preparation
7. Final Review
8. Publishing

All checklist tasks are initially marked as **Pending**.

> Note: In the current CA1 version, the checklist is read-only. Users cannot mark tasks as completed.

## Technologies Used

- **Language:** C++
- **Compiler:** GCC / Clang
- **Libraries:** iostream, string, limits
- **Editor:** Visual Studio Code
- **Version Control:** Git and GitHub

## Project Structure

```text
Podcast-Episode-Production-Checklist/
│
├── .vscode/
│   └── tasks.json
│
├── main.cpp
│
├── README.md
│
└── .gitignore
```

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/coder-nik200/Podcast-Episode-Production-Checklist.git
```

### 2. Navigate to the Project Directory

```bash
cd Podcast-Episode-Production-Checklist
```

### 3. Compile the Program

Using GCC:

```bash
g++ -std=c++11 main.cpp -o podcast-checklist
```

On macOS, you can also use Clang:

```bash
clang++ -std=c++11 main.cpp -o podcast-checklist
```

### 4. Run the Program

On macOS or Linux:

```bash
./podcast-checklist
```

On Windows:

```bash
podcast-checklist.exe
```

## Application Menu

When the program starts, the following menu is displayed:

```text
===== PODCAST EPISODE PRODUCTION CHECKLIST =====

1. Add New Episode
2. View All Episodes
3. View Episode Details
4. View Production Checklist
5. View Total Episodes
6. Exit

Enter your choice:
```

Select an option by entering its corresponding number.

## Input Validation

The application includes the following validation rules:

| Field | Validation |
|---|---|
| Episode ID | Must be between 1 and 999999 |
| Duplicate ID | Existing episode IDs are not allowed |
| Title | Cannot be empty |
| Host | Cannot be empty |
| Guest | Cannot be empty |
| Recording Date | Must follow YYYY-MM-DD format with basic month and day range checks |
| Duration | Must be between 1 and 1440 minutes |
| Episode Capacity | Maximum 30 episodes |

**Date validation limitation:** The current implementation checks the date format and basic month/day ranges. It does not validate the actual number of days in each month or leap years.

## Object-Oriented Programming Concepts

This project demonstrates the following C++ concepts:

| Concept | Implementation |
|---|---|
| Class and Objects | `PodcastEpisode` |
| Encapsulation | Private data members and public methods |
| Inline Functions | `getId()` and `getTitle()` |
| Static Data Member | `totalEpisodes` |
| Static Member Function | `getTotalEpisodes()` |
| Friend Function | `displayProductionStatus()` |
| This Pointer | Used inside `setDetails()` |
| Array of Objects | `episodes[MAX_EPISODES]` |
| Object Pointers | Used in `findEpisode()` |
| References | Used in `addEpisode()` |
| String Class | Stores episode information |

## Current Project Limitations

This is the CA1 implementation. The following features are not currently included:

- File handling and permanent data storage.
- Database integration.
- Editing or deleting episodes.
- Updating checklist task status.
- User authentication.
- Graphical user interface.

All episode records are stored in memory and are lost when the program exits.

## Future Enhancements

Possible improvements in later project phases include:

- Constructors and destructors.
- File-based data persistence.
- Searching and updating stored records.
- Deleting episodes.
- Updating production checklist status.
- More comprehensive input validation.
- Database integration.

## Academic Information

| Detail | Information |
|---|---|
| Project | Podcast Episode Production Checklist |
| Course Code | CAP455 |
| Course | Object-Oriented Programming using C++ |
| Programme | Master of Computer Applications (MCA) |
| University | Lovely Professional University |
| Current Phase | CA1 – Design and Create |
| Academic Session | 2026–2027 |

## Author

**Nitish Kumar Bharti**

GitHub: [coder-nik200](https://github.com/coder-nik200)

---

*Developed as part of the CAP455 C++ Minor Project.*
