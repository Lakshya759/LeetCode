class Solution:
    def asteroidCollision(self, a: List[int]) -> List[int]:
       n= len(a)
       stack=[]
       print(n)
       for i in range(n):
        print(a[i])
        if(a[i]<0):
            flag=1
            while(len(stack)>0 and stack[-1]>0 and stack[-1]<=(a[i]*(-1))):
                if(stack[-1]==(a[i]*(-1))):
                    flag=0
                    stack.pop()
                    break
                stack.pop()
                
            if((len(stack)==0 or stack[-1]<0) and flag==1):
                stack.append(a[i])
        else:
            stack.append(a[i])
            print(a[i])
       return stack

        