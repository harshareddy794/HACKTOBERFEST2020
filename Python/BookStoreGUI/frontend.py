#-------------------------------run the frontend.py---------------------------------------------------
from tkinter import *
import backend

def view_content():
    lst.delete(0,END)
    for line in backend.view():
        lst.insert(END,line)

def search_content():
    lst.delete(0,END)
    for line in backend.search(title_text.get(),author_text.get(),year_text.get(),isbn_text.get()):
        lst.insert(END,line)

def insert_content():
    backend.insert(title_text.get(),author_text.get(),year_text.get(),isbn_text.get())
    lst.delete(0,END)
    lst.insert(END,"Insert successfully")



def get_selectedrow(event):
    index = lst.curselection()[0]
    global selected_tuple
    selected_tuple = lst.get(index) # return tuple (1,"x","y",2020,123)
    e1.delete(0,END)
    e1.insert(END,selected_tuple[1])
    e2.delete(0,END)
    e2.insert(END,selected_tuple[2])
    e3.delete(0,END)
    e3.insert(END,selected_tuple[3])
    e4.delete(0,END)
    e4.insert(END,selected_tuple[4])

def delete_content():
    backend.delete(selected_tuple[0])

def update_content():
    backend.update(selected_tuple[0],title_text.get(),author_text.get(),year_text.get(),isbn_text.get())



window = Tk()
window.wm_title="BookStore"

l1 = Label(window,text="TITLE")
l1.grid(row=0,column=0)

l2 = Label(window,text="AUTHOR")
l2.grid(row=0,column=2)

l3 = Label(window,text="YEAR")
l3.grid(row=1,column=0)

l4 = Label(window,text="ISBN")
l4.grid(row=1,column=2)

title_text = StringVar()
e1 = Entry(window,textvariable=title_text)
e1.grid(row=0,column=1)

author_text = StringVar()
e2 = Entry(window,textvariable=author_text)
e2.grid(row=0,column=3)

year_text = StringVar()
e3 = Entry(window,textvariable=year_text)
e3.grid(row=1,column=1)

isbn_text = StringVar()
e4 = Entry(window,textvariable=isbn_text)
e4.grid(row=1,column=3)

lst = Listbox(window,height=6,width=40)
lst.grid(row=2,column=0,rowspan=10,columnspan=2)

sb = Scrollbar(window)
sb.grid(row=2,column=2,rowspan=6)

sb.configure(command = lst.yview)
lst.configure(yscrollcommand = sb.set)

lst.bind('<<ListboxSelect>>',get_selectedrow)

b0 = Button(window,text="VIEW ALL",width=13,command=view_content)
b0.grid(row=3,column=3)

b1 = Button(window,width=13,text="CLOSE",command=window.destroy)
b1.grid(row=2,column=3)

b2 = Button(window,text="SEARCH",width=13,command=search_content)
b2.grid(row=5,column=3)

b3 = Button(window,text="ADD",width=13,command=insert_content)
b3.grid(row=4,column=3)

b4 = Button(window,text="UPDATE",width=13,command=update_content)
b4.grid(row=6,column=3)

b5 = Button(window,text="DELETE",width=13,command=delete_content)
b5.grid(row=7,column=3)


window.mainloop()