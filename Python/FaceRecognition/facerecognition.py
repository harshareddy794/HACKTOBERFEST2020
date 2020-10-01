import face_recognition

image = face_recognition.load_image_file("Barack.jpg")
unknown_image=face_recognition.load_image_file("Trumph.jpg")

barack_encoding = face_recognition.face_encodings(image)[0]
unknown_encoding = face_recognition.face_encodings(unknown_image)[0]

results = face_recognition.compare_faces([barack_encoding],unknown_encoding)
print(results)
