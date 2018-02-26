import json
import random
while True:
    inp = list(raw_input())
    lis = inp
    try:
        if inp[0] != '{' or inp[-1] != '}':
            raise Exception("Not Valid JSON")

        for i in range(len(inp)):
            if inp[i]=='{' and inp[i+1]=='}':
                inp[i] = inp[i]+"\"key\":\"value\""
            elif inp[i]==':' and inp[i+1]=='}':
                inp[i] = "\"key\":\"value\""
            elif inp[i]==':':
                inp[i] = "\"key\":"
        inp = "".join(inp)
        json.loads(inp)
        print "1"
    except KeyError as ex:
        print "1"
    except Exception as ex:
        print "-1"

    break