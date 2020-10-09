from turtle import *
from random import randrange
from freegames import square, vector

#5 FUNCTIONALITY
def change(x, y):
    aim.x = x
    aim.y = y

def insideField(head):
    return -251 < head.x < 250 and -251 < head.y < 250

def move():
    head = snake[-1].copy()
    head.move(aim)

    if not insideField(head):
        square(head.x, head.y, 9, 'red')
        t.write("Game Over!  Score: {}".format(len(snake)))
        update()
        return

    snake.append(head)

    if head == food:
        food.x = randrange(-25, 25) * 10
        food.y = randrange(-25, 25) * 10
    else:
        snake.pop(0)

    clear()

    for body in snake:
        square(body.x, body.y, 9, 'black')

    square(food.x, food.y, 9, 'blue')
    update()
    ontimer(move, 100)

#1 WINDOW SETUP
window = Screen()
window.bgcolor("light green")
window.title("Snake Game")
setup(600, 600, 400, 50)

#2 MAKE FIELD AREA
hideturtle()
tracer(False)
t = Turtle()
t.hideturtle()
t.penup()
t.setpos(-250, 250)
t.pendown()
for i in range(4):
  t.forward(500)
  t.right(90)

#3 SETTING STARTING POSITIONS OF ELEMENTS
food = vector(0, 0)
square(food.x, food.y, 9, 'blue')
snake = [vector(10, 0)]
square(snake[-1].x, snake[-1].y, 9, 'black')
aim = vector(0, -10)

#4 LISTENING FROM THE KEY BOARD
listen()
onkey(lambda: change(10, 0), 'Right')
onkey(lambda: change(-10, 0), 'Left')
onkey(lambda: change(0, 10), 'Up')
onkey(lambda: change(0, -10), 'Down')

move()

done()
