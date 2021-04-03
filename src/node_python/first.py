import sys
import time
param1 = sys.argv[1]
time.sleep(1)
print("Print from pyhton, data from node: " + param1)

# send printed data back to node
sys.stdout.flush()