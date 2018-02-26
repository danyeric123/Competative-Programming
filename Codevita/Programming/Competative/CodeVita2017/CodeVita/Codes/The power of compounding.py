P = str(input())
R = str(input())
T = str(input())
try :
    #print (P,R,T)
    P = float(P)
    #print (P,R,T)
    R = float(R)
    #print (P,R,T)
    T = T.rstrip('0').rstrip('.') if '.' in T else T

    T = int(T)
   # print "Came Here"
    assert (P>0.0 and R>=0.0 and T>0)
    Sum = 0
    for i in range(0,T):
        Sum += P
        Sum += (Sum*R)/(100*12.000000000000000000)
    Sum = round(Sum)
    print("Final_Amount",Sum)
except Exception as ae:
    print("Invalid Input")
