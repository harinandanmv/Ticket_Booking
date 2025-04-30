# 🎟️ Ticket Booking System (C Project)

## 🌟 Overview
The **Ticket Booking System** is a beginner-friendly C project designed to simulate a basic ticket reservation platform. It allows users to log in, book or cancel seats, view the current seating layout, and manage a waitlist system for fully booked shows.

---

## ✨ Features
- 🔐 **Login system** with predefined usernames and passwords.
- 🪑 **Seat selection** by row and column with input validation.
- 🚫 **Prevents double booking** and informs users if seats are already taken.
- ⏳ **Waitlist management** when all seats are booked.
- ❌ **Ticket cancellation** with automatic reassignment from the waitlist.
- 🧾 **Display** seating arrangement and waitlist in real-time.

---

## 🛠️ Technologies Used
- **C**: Core language for logic and flow.
- **GCC**: Compiler used to run the application.
- **Standard Libraries**: `<stdio.h>`, `<stdlib.h>`, `<string.h>`.

---

## 🧪 How to Run
1. **Compile the code** using GCC:
   ```bash
   gcc ticket_booking.c -o ticket_booking
   ```

2. **Run the program**:
   ```bash
   ./ticket_booking
   ```

3. **Login credentials** (examples):
   - Username: `user1` | Password: `pass1`
   - Username: `user2` | Password: `pass2`
   - Username: `user3` | Password: `pass3`

---

## 📂 Project Structure
```
ticket-booking/
|-- ticket_booking.c      # Main C source file
|-- README.md             # Project documentation (this file)
```

---

## 💡 Possible Extensions
- 🗃️ **Save bookings to a file** for data persistence.
- 📅 **Add date/time support** for different show timings.
- 👤 **User registration system** for dynamic account creation.

---

## 🙌 Acknowledgements
This project was created as a learning exercise to help understand basic C programming, including:
- Structs
- Arrays
- String manipulation
- Control structures
- User input handling

---

## 📜 License
This project is free to use for learning and educational purposes.

---

## 📥 Clone the Repository

To get a copy of this project locally, use the command below:

```bash
git clone https://github.com/harinandanmv/Ticket_Booking.git
