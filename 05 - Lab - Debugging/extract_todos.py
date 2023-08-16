'''
This is a simple python script to extract the #TODO: questions from a cpp
file and save out (sorted) to a text file.


Written by Clinton Woodward <cwoodward@swin.edu.au>

You do not need to understand this file for the unit COS30031 Games Programming.
It is provided as-is for those that are curious.
'''

cpp_file = "task05_struct_ptrs_c_arrays.cpp"
txt_file = "question_lines.txt"

data = []
with open(cpp_file) as f:
    for i, l in enumerate(f.readlines()):
        if "#TODO: " in l:
            l = l.split("#TODO: ")[1].strip()
            if "Q." == l[:2]:
                q_no = l.split()[0].replace("Q.", "")
                if "-" not in q_no:
                    q_no = int(q_no)
                    l = " ".join(l.split()[1:])
                    data.append([q_no, i, l])

data = sorted(data)

with open(txt_file, "w") as f:
    for d in data:
        f.write("Q.%d [line %d] %s \n" % tuple(d))

