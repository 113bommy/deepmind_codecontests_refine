sx,sy,tx,ty = map(int,input().split())
print("U"*(ty-sy)+"R"*(tx-sx)+"D"*(ty-sy)+"L"*(ty-sy)+"L"+"U"*(ty-sy+1)+"R"*(tx-sx+1)+"D"+"R"+"D"*(ty-sy+1)+"L"*(tx-sy+1)+"U")
