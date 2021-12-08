a = "aBc deF"
print("a =", a)
print("a.upper() =", a.upper())
print("a.lower() =", a.lower())
print("a.title() =", a.title())
print()

a = [1, 2, 3, "456", "seven", [89, "ten"]]
print("a =", a)
print()
a.insert(2, 2.5)
print("a.insert(2, 2.5);\na =", a)
print()
a.append([11, 12])
print("a.append([11, 12]);\na =", a)
print()
b = a.copy()
a = [1, 2, 3]
print("b = a.copy; \na = [1,2,3];\nb =", b, "\na =", a)
print()
a.clear()
print("a.clear() \na =", a)
print()
