```markdown
# 🎟️ Ticket Booking System (C Project)

This is a simple **console-based ticket booking system** for a theater, written in **C**. It allows users to log in, book and cancel seats, view the seating arrangement, and manage a waiting list.

---

## 📌 Features

- ✅ User login with predefined credentials
- ✅ Seat booking with row and column selection
- ✅ Prevents booking of already reserved seats
- ✅ Waitlist for full bookings
- ✅ Ticket cancellation
- ✅ Auto-assign waitlisted customers to newly available seats
- ✅ Display current seating arrangement
- ✅ Display current waitlist

---

## 🛠 Technologies Used

- Language: **C**
- Concepts: Arrays, Strings, Structures

---

## 🚀 How to Run

1. **Compile the program:**

   ```bash
   gcc ticket_booking.c -o ticket_booking
   ```

2. **Run the executable:**

   ```bash
   ./ticket_booking
   ```

3. **Login:**

   Use any of these credentials:
   - `user1 / pass1`
   - `user2 / pass2`
   - `user3 / pass3`

---

## 💡 How It Works

- The system keeps track of a 5x5 theater seating.
- If a selected seat is booked, and all seats are full, the customer is added to a waitlist.
- If seats are available, the user is prompted to select a different seat.
- Canceling a ticket frees the seat and automatically assigns it to the first person in the waitlist (if any).

---

## 🗃 Example Output

```
1. Book a Ticket
2. Cancel a Ticket
3. Display Seating Arrangement
4. Display Waitlist
5. Exit
```

---

## 🧑‍💻 Author

**Harinandan M V**

---

## 📂 Git Setup Notes

Make sure your default branch is `main`. To push:

```bash
git push -u origin main
```

If you're renaming from `master`, use:

```bash
git branch -m main
git push -u origin main
```

---

## ✅ License

This project is for educational purposes and open to modification for learning.
```