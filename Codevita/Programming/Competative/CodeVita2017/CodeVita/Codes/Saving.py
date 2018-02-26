M = float(input())
T = float(input())
R = float(input())
RM = R
T= T-1
while(T>0):
    A = RM/(1+R/1200.00000)
    I = RM - A
    RM = RM + M -I
    T-=1

print(round(RM))
