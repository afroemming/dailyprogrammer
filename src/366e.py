def funnel(a, b):
    for i, letter in enumerate(a):
        if a[:i] + a[i+1:] == b:
            return True
    return False

def bonus(word):
    out = []
    with open('enable1.txt') as f:
        for line in f:
            if funnel(word, line.strip()) and not line.strip() in out:
                out.append(line.strip())
    return out
    
if __name__ == '__main__':
    assert funnel("leave", "eave")
    assert funnel("reset", "rest") 
    assert funnel("dragoon", "dragon") 
    assert not funnel("eave", "leave") 
    assert not funnel("sleet", "lets") 
    assert not funnel("skiff", "ski") 
    assert bonus("dragoon") == ["dragon"]
    assert sorted(bonus("boats")) == sorted(["oats", "bats", "bots", "boas", "boat"])
    assert bonus("affidavit") == []