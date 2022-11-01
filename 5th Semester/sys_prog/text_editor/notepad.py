import os
# import win32api
# import win32print
from tkinter import *
from tkinter import font
from tkinter import colorchooser
from tkinter.messagebox import showinfo, askokcancel, showinfo, WARNING
from tkinter.filedialog import askopenfilename, asksaveasfilename


# creating a new file
def newFile():
    global file
    root.title('Untitled - Notepad')
    file = None
    textarea.delete(1.0, END)


# opening a new file
def openFile():
    global file
    file = askopenfilename(defaultextension='.txt', filetypes=[
                           ('All Files', '*.*'), ('Text Documents', '*.txt')])
    if file == '':
        file = None
    else:
        root.title(os.path.basename(file) + ' - Notepad')
        textarea.delete(1.0, END)
        f = open(file, 'r')
        textarea.insert(1.0, f.read())
        f.close()


# saving a new file
def saveFile():
    global file
    if file == None:
        file = asksaveasfilename(defaultextension='.txt', filetypes=[
            ('All Files', '*.*'), ('Text Documents', '*.txt')])
        if file == "":
            file = None
        else:
            # Save as new file
            f = open(file, 'w')
            f.write(textarea.get(1.0, END))
            f.close()

            # change title
            root.title(os.path.basename(file) + ' - Notepad')
            print('File Saved')
    else:
        # Save the file
        f = open(file, 'w')
        f.write(textarea.get(1.0, END))
        f.close()


# saving as new file
def saveAsFile():
    global file
    if file != None:
        file = asksaveasfilename(defaultextension='.txt', filetypes=[
            ('All Files', '*.*'), ('Text Documents', '*.txt')])

        # Save as new file
        f = open(file, 'w')
        f.write(textarea.get(1.0, END))
        f.close()

        # change title
        root.title(os.path.basename(file) + ' - Notepad')
        print('File Saved')
    else:
        saveFile()


# printing a new file
def printFile():
    global file
    global textarea
    saveFile()
    if file == None:
        showinfo('Alert!', 'Save the file first.')
    else:
        print(file)
        print("Printing funcition")
        # win32api.ShellExecute(0, 'print', file, None, '.', 0)
        print("Completed printing")


# quit the instance
def quitApp():
    global textarea
    global file
    global root
    if textarea.edit_modified():
        answer = askokcancel(
            title='Alert!', message='Do you want to save the file?', icon=WARNING)
        if answer:
            saveFile()
            root.destroy()
        else:
            root.destroy()
    else:
        root.destroy()
    root.destroy()


# performing cut
def cut():
    textarea.event_generate("<<Cut>>")


# performing copy
def copy():
    textarea.event_generate("<<Copy>>")


# performing paste
def paste():
    textarea.event_generate("<<Paste>>")


# performing bold
def bold():
    global textarea
    bold_font = font.Font(textarea, textarea.cget('font'))
    bold_font.configure(weight='bold')

    textarea.tag_configure('bold', font=bold_font)

    curr_tags = textarea.tag_names('sel.first')
    # print(curr_tags)

    if 'bold' in curr_tags:
        textarea.tag_remove('bold', 'sel.first', 'sel.last')
    else:
        textarea.tag_add('bold', 'sel.first', 'sel.last')


# performing italic
def italic():
    global textarea
    italic_font = font.Font(textarea, textarea.cget('font'))
    italic_font.configure(slant='italic')

    textarea.tag_configure('italic', font=italic_font)

    curr_tags = textarea.tag_names('sel.first')
    # print(curr_tags)

    if 'italic' in curr_tags:
        textarea.tag_remove('italic', 'sel.first', 'sel.last')
    else:
        textarea.tag_add('italic', 'sel.first', 'sel.last')


# changing text color
def color():
    my_color = colorchooser.askcolor()[1]

    if my_color:
        global textarea
        color_font = font.Font(textarea, textarea.cget('font'))

        color_name = 'color' + str(my_color)

        textarea.tag_configure(
            color_name, font=color_font, foreground=my_color)

        curr_tags = textarea.tag_names('sel.first')
        # print(curr_tags)

        # if 'color' in curr_tags:
        # textarea.tag_remove('color', 'sel.first', 'sel.last')
        # else:
        textarea.tag_add(color_name, 'sel.first', 'sel.last')


# changing background color
def bgColor():
    my_color = colorchooser.askcolor()[1]

    if (my_color):
        global textarea
        textarea.config(bg=my_color)


# changing foreground color
def fgColor():
    global textarea
    my_color = colorchooser.askcolor()[1]

    if (my_color):
        cur_tags = textarea.tag_names()
        for tag in cur_tags:
            if tag != 'sel':
                textarea.tag_delete(tag)

        textarea.config(fg=my_color)


# viewing about
def about():
    showinfo('Notepad', 'Made by Rohit.')


# saveAction handler
def saveAction():
    global textarea
    if textarea.edit_modified():
        answer = askokcancel(
            title='Save As', message='Do you want to save the file?', icon=WARNING)
        if answer:
            saveFile()
            root.destroy()
        else:
            root.destroy()
    else:
        root.destroy()


def show_or_hide():
    global find_replace_menu
    # tt = find_replace_menu.cget('label')
    tt = find_replace_menu.entrycget(0, 'label')
    if tt == 'show':
        fram.pack(side=TOP)
        find_replace_menu.entryconfigure(1, label='hide')
    else:
        fram.pack_forget()
        find_replace_menu.entryconfigure(1, label='show')
    # print(tt)


root = Tk()
root.geometry('444x555')
root.title('Untitled - Notepad')
root.wm_iconbitmap('fav.ico')

# textarea
textarea = Text(root, font='lucida 12', undo=True, wrap='none')
file = None
textarea.pack(expand=True, fill=BOTH)

# Menu Bar
menuBar = Menu(root)
fileMenu = Menu(menuBar, tearoff=0)
# to open new file
fileMenu.add_command(label='New', command=newFile)
# to open already existing file
fileMenu.add_command(label='Open', command=openFile)
# to save current file
fileMenu.add_command(label='Save', command=saveFile)
fileMenu.add_command(label='Save As', command=saveAsFile)

fileMenu.add_separator()
fileMenu.add_command(label='Print', command=printFile)
fileMenu.add_separator()
fileMenu.add_command(label='Exit', command=quitApp)

menuBar.add_cascade(label='File', menu=fileMenu)


# edit menu
editMenu = Menu(menuBar, tearoff=0)
editMenu.add_command(label='Cut', command=cut, accelerator='(Ctrl+X)')
editMenu.add_command(label='Copy', command=copy, accelerator='(Ctrl+C)')
editMenu.add_command(label='Paste', command=paste, accelerator='(Ctrl+V)')
editMenu.add_separator()
editMenu.add_command(
    label='Undo', command=textarea.edit_undo, accelerator='(Ctrl+Z)')
editMenu.add_command(
    label='Redo', command=textarea.edit_redo, accelerator='(Ctrl+Y)')
editMenu.add_separator()
editMenu.add_command(label='Selected Font Color', command=color)
editMenu.add_command(label='Background Color', command=bgColor)
editMenu.add_command(label='Foreground Color', command=fgColor)

# find or replace implementation
find_replace_menu = Menu(editMenu, tearoff=0)
find_replace_menu.add_command(label='show', command=show_or_hide)
editMenu.add_cascade(label='Find/Replace', menu=find_replace_menu)

# font menu
fontMenu = Menu(editMenu, tearoff=0)
fontMenu.add_command(label='Bold', command=bold)
fontMenu.add_command(label='Italic', command=italic)
editMenu.add_cascade(label='Fonts/Style', menu=fontMenu)

menuBar.add_cascade(label='Edit', menu=editMenu)

# help menu
helpMenu = Menu(menuBar, tearoff=0)
helpMenu.add_command(label='About', command=about)
menuBar.add_cascade(label='Help', menu=helpMenu)


root.config(menu=menuBar)

# scrollbar addition
scrollBar = Scrollbar(textarea)
scrollBar.pack(side=RIGHT, fill=Y)
scrollBar.config(command=textarea.yview)
textarea.config(yscrollcommand=scrollBar.set)

scrollBarHor = Scrollbar(textarea)
scrollBarHor.pack(side=BOTTOM, fill=X)
scrollBarHor.config(command=textarea.xview)
textarea.config(xscrollcommand=scrollBarHor.set)


# -->


# root window is the parent window
fram = Frame(root)

# Creating Label, Entry Box, Button
# and packing them adding label to
# search box
Label(fram, text='Find').pack(side=LEFT)

# adding of single line text box
edit = Entry(fram)

# positioning of text box
edit.pack(side=LEFT, fill=BOTH, expand=1)

# setting focus
edit.focus_set()

# adding of search button
Find = Button(fram, text='Find')
Find.pack(side=LEFT)


Label(fram, text="Replace With ").pack(side=LEFT)

edit2 = Entry(fram)
edit2.pack(side=LEFT, fill=BOTH, expand=1)
edit2.focus_set()

replace = Button(fram, text='FindNReplace')
replace.pack(side=LEFT)

# fram.pack(side=TOP)

# text box in root window
# text = Text(root)

# # text input area at index 1 in text window
# text.insert('1.0', '''Type your text here''')
# text.pack(side=BOTTOM)

# function to search string in text


def find():

    # remove tag 'found' from index 1 to END
    # text.tag_remove('found', '1.0', END)
    textarea.tag_remove('found', '1.0', END)

    # returns to widget currently in focus
    s = edit.get()

    if (s):
        idx = '1.0'
        while 1:
            # searches for desired string from index 1
            idx = textarea.search(s, idx, nocase=1,
                                  stopindex=END)

            if not idx:
                break

            # last index sum of current index and
            # length of text
            lastidx = '% s+% dc' % (idx, len(s))

            # overwrite 'Found' at idx
            textarea.tag_add('found', idx, lastidx)
            idx = lastidx

        # mark located string as red

        textarea.tag_config('found', foreground='red')
    edit.focus_set()


def findNreplace():

    # remove tag 'found' from index 1 to END
    textarea.tag_remove('found', '1.0', END)

    # returns to widget currently in focus
    s = edit.get()
    r = edit2.get()

    if (s and r):
        idx = '1.0'
        while 1:
            # searches for desired string from index 1
            idx = textarea.search(s, idx, nocase=1,
                                  stopindex=END)
            print(idx)
            if not idx:
                break

            # last index sum of current index and
            # length of text
            lastidx = '% s+% dc' % (idx, len(s))

            textarea.delete(idx, lastidx)
            textarea.insert(idx, r)

            lastidx = '% s+% dc' % (idx, len(r))

            # overwrite 'Found' at idx
            textarea.tag_add('found', idx, lastidx)
            idx = lastidx

        # mark located string as red
        textarea.tag_config('found', foreground='green', background='yellow')
    edit.focus_set()


Find.config(command=find)
replace.config(command=findNreplace)


# -->

# closing action without saving
root.protocol('WM_DELETE_WINDOW', saveAction)

root.mainloop()
