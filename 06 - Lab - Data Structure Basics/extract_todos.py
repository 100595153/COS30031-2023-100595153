'''
This is a simple python script to extract the #TODO: questions from a cpp
file and save out (sorted) to a text file.


Written by Clinton Woodward <cwoodward@swin.edu.au>

You do not need to understand this file for the unit COS30031 Games Programming.
It is provided as-is for those that are curious.
'''

cpp_file = "task06_collection_basics.cpp"
txt_file = "question_lines.txt"

data = []
with open(cpp_file) as f:
    for i, l in enumerate(f.readlines()):
        if "#TODO: Q." in l:
            l = l.split("#TODO: Q.")[1].strip()
            q_no = l.split()[0].replace("Q.", "")
            # q_no = int(q_no)
            l = " ".join(l.split()[1:])
            data.append([q_no, i, l])

# data = sorted(data)

with open(txt_file, "w") as f:
    for d in data:
        f.write("Q.%s [line %d] %s \n" % tuple(d))

