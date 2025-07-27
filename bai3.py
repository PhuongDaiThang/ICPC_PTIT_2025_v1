s = input().strip()        

l = s.find('A')             
r = s.rfind('Z')            

print(r - l + 1 if l != -1 and r != -1 and l <= r else 0)
