def hexcolor(red, green, blue):
    return '#{:02X}{:02X}{:02X}'.format(red, green, blue)

def blend(*args):
    r, g, b = [], [], []
    for code in args:
        r.append(int(code[1:3], 16))
        g.append(int(code[3:5], 16))
        b.append(int(code[5:7], 16))
    return hexcolor(int(round(sum(r)/len(r))), int(round(sum(g)/len(g))), int(round(sum(b)/len(b))))
    
if __name__ == "__main__":
    assert hexcolor(255, 99, 71) == "#FF6347"
    assert hexcolor(184, 134, 11) == "#B8860B"
    assert hexcolor(0, 0, 205) == "#0000CD"
    assert blend("#000000", "#778899") == "#3C444C"