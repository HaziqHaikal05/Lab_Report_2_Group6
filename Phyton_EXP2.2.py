import serial
import matplotlib.pyplot as plt
ser = serial.Serial('COM3', 9600)

plt.ion() # Interactive mode for real-time plot
fig, ax = plt.subplots()
x_vals, y_vals = [], []
try:
    while True:
        pot_value = ser.readline().decode().strip()
        print("Potentiometer Value:", pot_value)
        x_vals.append(len(x_vals))
        y_vals.append(int(pot_value))
        ax.clear()
        ax.plot(x_vals, y_vals) # Plot potentiometer readings
        plt.pause(0.1) # Update plot
except KeyboardInterrupt:
    ser.close()
    plt.ioff() # Turn off interactive mode
    plt.show() # Final plot display
    print("Serial connection closed.")
