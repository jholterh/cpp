import subprocess

expected_output = """a = 3, b = 2
min( a, b ) = 2
max( a, b ) = 3
c = chaine2, d = chaine1
min( c, d ) = chaine1
max( c, d ) = chaine2"""

# Run your program
result = subprocess.run(['./main'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
output = result.stdout.decode().strip()

expected_lines = expected_output.split('\n')
output_lines = output.split('\n')

print("\nTesting output line by line:\n")

all_pass = True
for i in range(max(len(expected_lines), len(output_lines))):
    expected = expected_lines[i] if i < len(expected_lines) else ""
    actual = output_lines[i] if i < len(output_lines) else ""
    check = "✅" if expected == actual else "❌"
    if expected == actual:
        print(f"{expected} {check}")
    else:
        print(f"Expected: {expected}")
        print(f"Got     : {actual} {check}")
        all_pass = False

print("\n" + ("All lines correct! 🎉" if all_pass else "Some lines are incorrect."))

