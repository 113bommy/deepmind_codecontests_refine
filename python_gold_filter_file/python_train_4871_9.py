H,W = map(int, input().split())
print(1 if H*W in [H,W] else W*(H//2)+(W//2+W%2)*(H%2))