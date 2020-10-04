import random
import math
import turtle

j=200
k=j
multiplyby=2
xpositions=[]
ypositions=[]

wn=turtle.Screen()
wn.bgcolor("Black")

pen=turtle.Turtle()
pen.penup()
pen.speed(0)
pen.color("white")
# pen.setposition(0,0)
pen.hideturtle()
pen.setposition(-200,0)
pen.right(90)
pen.pendown()
pen.circle(200)

def findmultiple(var):
	global ans,multiplyby
	ans=var*multiplyby
	if len(str(ans))>1:
		ans%=j

def registerpos():
	global positions
	xpositions.append(pen.xcor())
	ypositions.append(pen.ycor())

for i in range(j+1):
	pen.pendown()
	pen.dot(3,'red')
	registerpos()
	pen.penup()
	pen.circle(200,-(360/j))

for o in range(0,k+1):	
	pen.goto(xpositions[o],ypositions[o])
	findmultiple(o)
	print(o,'    ',ans)
	orgx=pen.xcor()
	orgy=pen.ycor()
	pen.pendown()
	pen.goto(xpositions[ans],ypositions[ans])
	pen.penup()
	pen.goto(orgx,orgy)


wn.mainloop()
