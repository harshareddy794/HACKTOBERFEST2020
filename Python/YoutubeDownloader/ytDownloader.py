from pytube import YouTube

#Prompt for Link of the Youtube
link = input("Enter the link of YouTube video you want to download:  ")
yt = YouTube(link)

#Showing Title, description and length of Video
print("Title: ",yt.title)

print("\nDescription: ",yt.description)

print("\nLength of video: ",yt.length)

#Getting the highest resolution possible
ys = yt.streams.get_highest_resolution()

#Starting download
print("Downloading...")
ys.download()
print("Download completed!!")
