a = "aBc cjF"
print("a =", a)
print("a.upper() =", a.upper())
print("a.lower() =", a.lower())
print("a.title() =", a.title())

a = [1, 2, 3, "abc", [45, "de"]]
print("a =", a)
a.insert(0, 10)
print("a.insert(0, 10); a =", a)
a.append(100)
print("a.append(100); a =", a)
b = a.copy()
a = [1, 2, 3]
print("b = a.copy; a = [1,2,3]; b =", b)
print("a.clear(); a=  ", a.clear())

