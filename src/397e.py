def derangement(n):
    if n == 1:
        return 0
    if n == 0:
        return 1  
    return (n - 1) * (derangement(n - 1) + derangement(n - 2))

if __name__=="__main__":
    assert derangement(6) == 265, "{}!=265".format(derangement(6))
    assert derangement(9) == 133496, "{}!=133496".format(derangement(9))
    assert derangement(14) == 32071101049, "{}!=32071101049".format(derangement(14))