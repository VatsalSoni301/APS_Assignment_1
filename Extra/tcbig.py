import random
import string

t=10
print t
for i in range(t):
        x = ''.join(random.choice(string.digits) for _ in range(random.randint(5, 10)))
        y = ''.join(random.choice(string.digits) for _ in range(random.randint(5, 10)))

        print x
        print y
        print 5