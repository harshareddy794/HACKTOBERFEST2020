# HTML Web Scrapping using bs4

# STEP0: SETTING UP THE ENVIRONMENT
    # Imported requests and beutifulSoup(bs4)

import requests
from bs4 import BeautifulSoup
url = "https://codewithharry.com/"

# STEP1: GET THE HTML

r = requests.get(url)
htmlcontent = r.content
print(htmlcontent)

# STEP2: PARSE THE HTML

soup = BeautifulSoup(htmlcontent, 'html.parser')
print(soup.prettify)

# STEP3: HTML TREE TRAVERSAL
    #Tag
    #Navigable String
    #BeautifulSoup
    #Comment

title = soup.title  
    print(title)

paras = soup.find_all('p')
    print(paras)

anchors = soup.find_all('a')
    print(anchors)

first_para = soup.find('p')
    print(first_para)

# Get classes of any element in HTML Page
print(first_para['class'])

# Get all the elements of a specific class(eg. lead)
print(soup.find_all("p", class_="lead"))

# To get text from tags/soup
print(soup.find('p').get_text())
print(soup.get_text())

# To get all links of a page 
anchors = soup.find_all('a')
all_links = set()

for link in anchors:
    if(link.get('href') != "#"):
        linkText = "https://codewithharry.com" + link.get('href')
        all_links.add(link)
    print(linkText)


# For comment in HTML Tree Traversal

markup = "<p><!-- this is a comment  --></p>"
soup2 = BeautifulSoup(markup)
print(soup2.p.string)


# To find elements of a particular id

navbarSupportedContent = soup.find(id='navbarSupportedContent')
for element in navbarSupportedContent.children:     # we can use .contents also but for large websites .children is more effecient
    print(element)

for item in navbarSupportedContent.strings:
    print(item)

for item in navbarSupportedContent.stripped_strings:
   print(item)

print(navbarSupportedContent.parent)

for item in navbarSupportedContent.parents:
   print(item.name)

# Sibblings

print(navbarSupportedContent.next_sibling)

print(navbarSupportedContent.next_sibling.next_sibling)

print(navbarSupportedContent.previous_sibling)

print(navbarSupportedContent.previous_sibling.previous_sibling)

# CSS Selecting

# # is for id

id_element = soup.select('#loginModal')
print(id_element)

# . is for class

class_element = soup.select('.loginModal')
print(class_element)