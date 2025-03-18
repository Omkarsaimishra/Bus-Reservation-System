
# Bus Seat Reservation System 🚌

A C-based command-line application with text-based GUI for comprehensive bus seat reservations.

![Main Interface](screenshots/Bus%20reservation%20panel.png)

## Features ✨
- **CMD Text GUI** with menu-driven interface
- **Authentication System** (Username: `user`, Password: `pass`)
- Bus schedule management
- Seat reservation tracking
- Passenger name database
- Payment processing interface
- Real-time seat availability display
- Text-based data storage

## Screenshots 📸

### Login Interface
![Login Interface](screenshots/login.png)
*Command-line authentication screen with secure input masking*

### Bus Management
![Bus List](screenshots/bus%20list.png)
*Text-based interface for viewing available buses*

### Reservation Process
![Reservation Panel](screenshots/seat%20reservation%20panel.png)
*Seat selection interface with visual availability status*

![Bus Reservation Panel](screenshots/Bus%20reservation%20panel.png)
*Main reservation interface with booking options*

### Database Management
![Seat Database](screenshots/Seat%20number%20data%20base.png)
*Database view showing seat-number-to-passenger mapping*

![Name Database](screenshots/Name%20data%20base.png)
*Passenger information database storage*

### Payment System
![Payment Interface](screenshots/Payment.png)
*Text-based payment processing screen*

### Existing Reservations
![Existing Seats](screenshots/existing%20seat.png)
*Display of current reservations and seat status*

## Installation & Compilation 💻

### Requirements
- GCC Compiler
- Windows CMD/Linux Terminal

```bash
# Clone repository
git clone https://github.com/yourusername/bus-reservation-c.git
cd bus-reservation-c

# Compile program
gcc main.c -o bus_reservation

# Run executable
./bus_reservation
```

## Usage Guide 📋

1. **Login**:
   ```
   Enter Username: user
   Enter Password: pass
   ```

2. **Main Menu**:
   ```
   [1] New Reservation
   [2] View Bus List
   [3] Check Seat Availability
   [4] Payment Portal
   [5] View Databases
   [6] Exit
   ```

3. Follow on-screen instructions using number keys

## File Structure 📁
```
.
├── src/
│   ├── main.c             # Core application logic
│   ├── auth.c             # Authentication system
│   └── database.c         # File handling operations
├── data/
│   ├── buses.dat          # Bus schedule storage
│   ├── seats.dat          # Seat reservations
│   └── passengers.dat     # Passenger information
└── screenshots/           # Interface previews
    ├── login.png
    ├── Payment.png
    └── ...other images
```

## Security Notes 🔐
- Default credentials for demonstration only
- Change credentials in `auth.c` for production
- Data stored in plain text files (not secure for real use)
- No actual payment processing - for simulation only

## Contributing 🤝
1. Fork the repository
2. Create feature branch (`git checkout -b feature/feature-name`)
3. Commit changes (`git commit -m 'Add new feature'`)
4. Push to branch (`git push origin feature/feature-name`)
5. Open Pull Request

## License 📄
MIT License - See [LICENSE](LICENSE) for details
```

**Important Recommendations:**
1. Create a dedicated `screenshots` folder in your repository
2. Optimize PNG files for web (reduce file size while maintaining clarity)
3. Add alt-text descriptions for accessibility
4. Consider adding a diagram explaining system architecture
5. Include a version history section if you have multiple releases
6. Add a troubleshooting section for common compilation issues

Would you like me to add any specific technical details about the C implementation or create additional documentation sections?
