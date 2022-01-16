# python module to create GUI		
from tkinter import *
		
root = Tk()
root.title("CRYPTOGRAPHY")
root.geometry("500x200") 


def encryptMessage():	
	pt = e1.get()	

	result = ""

	for i in range (len(pt)):
		char = pt[i]

		# Encrypt uppercase characters
		if (char.isupper()):
			result += chr((25-ord(char)+65)+65)
 
        # Encrypt lowercase characters
		elif (char.islower()):
			result += chr((25-ord(char)+97)+97)
		else:
			result += pt[i]
	e2.delete(0, END)
	e2.insert(0, result)
		

def decryptMessage():
	ct = e3.get()	

	result = ""

	for i in range (len(ct)):
		char = ct[i]

		# Decrypt uppercase characters
		if (char.isupper()):
			result += chr((25-ord(char)+65)+65)
 
        # Decrypt lowercase characters
		elif (char.islower()):
			result += chr((25-ord(char)+97)+97)
		else:
			result += ct[i]
	e4.delete(0, END)
	e4.insert(0, result)	
	

	
# creating labels and positioning them on the grid
label1 = Label(root, text ='Plain Text')			
label1.grid(row = 10, column = 1)
label2 = Label(root, text ='Encrypted Text')
label2.grid(row = 11, column = 1)
l3 = Label(root, text ="Cipher Text")
l3.grid(row = 10, column = 10)
l4 = Label(root, text ="Decrypted Text")
l4.grid(row = 11, column = 10)

# creating entries and positioning them on the grid
e1 = Entry(root)
e1.grid(row = 10, column = 2)
e2 = Entry(root)
e2.grid(row = 11, column = 2)
e3 = Entry(root)
e3.grid(row = 10, column = 11)
e4 = Entry(root)
e4.grid(row = 11, column = 11)

# creating encryption button to produce the output
ent = Button(root, text = "Encrypt", bg ="blue", fg ="white", command = encryptMessage)
ent.grid(row = 13, column = 2)

# creating decryption button to produce the output
b2 = Button(root, text = "Decrypt", bg ="blue", fg ="white", command = decryptMessage)
b2.grid(row = 13, column = 11)


root.mainloop()
