import face_recognition
import cv2
import numpy as np

# This is a code of running face recognition on live video from webcam.
#   1. Process each video frame at 1/4 resolution
#   2. Only detect faces in every other frame of video.

# OpenCV used only to read webcam.

# Get a reference to webcam #0 (the default one)
video_capture = cv2.VideoCapture(0)

# You need to add sample images and add its path in codes in loading

# Load sample picture and learn how to recognize it.
s1_image = face_recognition.load_image_file("sample1.jpg")
s1_face_encoding = face_recognition.face_encodings(s1_image)[0]

# Load second sample picture and learn how to recognize it.
s2_image = face_recognition.load_image_file("sample2.jpg")
s2_face_encoding = face_recognition.face_encodings(s2_image)[0]

# Load third sample picture and learn how to recognize it.
s3_image = face_recognition.load_image_file("sample3.jpg")
s3_face_encoding = face_recognition.face_encodings(s3_image)[0]

# Create arrays of known face encodings and their names
known_face_encodings = [
    s1_face_encoding,
    s2_face_encoding,
    s3_face_encodingq
]
known_face_names = [
    "Sample 1",
    "Sample 2 ",
    "Sample 3"
]

# Initialize some variables
face_locations = []
face_encodings = []
face_names = []
process_this_frame = True

while True:
    # Grab a single frame of video
    ret, frame = video_capture.read()

    # Resize frame of video to 1/4 size for faster face recognition processing
    small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)

    rgb_small_frame = small_frame[:, :, ::-1]

    # Only process every other frame of video to save time
    if process_this_frame:
        # Find all the faces and face encodings in the current frame of video
        face_locations = face_recognition.face_locations(rgb_small_frame)
        face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)

        face_names = []
        for face_encoding in face_encodings:
            # See if the face is a match for the known face(s)
            matches = face_recognition.compare_faces(known_face_encodings, face_encoding)
            name = "Unknown"

            face_distances = face_recognition.face_distance(known_face_encodings, face_encoding)
            best_match_index = np.argmin(face_distances)
            if matches[best_match_index]:
                name = known_face_names[best_match_index]

            face_names.append(name)

    process_this_frame = not process_this_frame


    # Display the results
    for (top, right, bottom, left), name in zip(face_locations, face_names):
        # Scale back up face locations since the frame detected in was scaled to 1/4 size
        top *= 4
        right *= 4
        bottom *= 4
        left *= 4

        # Draws a box around the face
        cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)

        # Labels with a name below the face
        cv2.rectangle(frame, (left, bottom - 35), (right, bottom), (0, 0, 255), cv2.FILLED)
        font = cv2.FONT_HERSHEY_DUPLEX
        cv2.putText(frame, name, (left + 6, bottom - 6), font, 1.0, (255, 255, 255), 1)

    # Display the result image
    cv2.imshow('Video', frame)

    # Enter 'q' to quit!
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

video_capture.release()
cv2.destroyAllWindows()
