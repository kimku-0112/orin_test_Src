import cv2

def main():
    # Initialize the first USB camera
    cap1 = cv2.VideoCapture(0)

    # Initialize the second USB camera
    cap2 = cv2.VideoCapture(2)
    
   # Initialize the second USB camera
    cap3 = cv2.VideoCapture(4)

    while True:
        # Capture frame from first camera
        ret1, frame1 = cap1.read()

        # Capture frame from second camera
        ret2, frame2 = cap2.read()
        
        # Capture frame from second camera
        ret3, frame3 = cap3.read()

        # Display the resulting frames in separate windows
        cv2.imshow('Camera 1', frame1)
        cv2.imshow('Camera 2', frame2)
        cv2.imshow('Camera 3', frame3)

        # Press 'q' to exit
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Release the captures
    cap1.release()
    cap2.release()
    cap3.release()    
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()

