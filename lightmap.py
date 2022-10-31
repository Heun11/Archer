# 9x9 lightmap 0-10
lm = [
    [0 ,0 ,1 ,3 ,3 ,3 ,1 ,0 ,0 ],
    [0 ,1 ,3 ,5 ,5 ,5 ,3 ,1 ,0 ],
    [1 ,3 ,5 ,7 ,7 ,7 ,5 ,3 ,1 ],
    [3 ,5 ,7 ,8 ,9 ,8 ,7 ,5 ,3 ],
    [3 ,5 ,7 ,9 ,10,9 ,7 ,5 ,3 ],
    [3 ,5 ,7 ,8 ,9 ,8 ,7 ,5 ,3 ],
    [1 ,3 ,5 ,7 ,7 ,7 ,5 ,3 ,1 ],
    [0 ,1 ,3 ,5 ,5 ,5 ,3 ,1 ,0 ],
    [0 ,0 ,1 ,3 ,3 ,3 ,1 ,0 ,0 ]
]

# convert to float array in c
def covnert_to_c_lightmap(lm):
    lm_c = "{\n"
    for i in range(9):
        lm_c += "\t"
        for j in range(9):
            lm_c += str(float(lm[i][j]/10))+"f, "
        lm_c+="\n"
    lm_c+="};"
    return lm_c

print(covnert_to_c_lightmap(lm))

