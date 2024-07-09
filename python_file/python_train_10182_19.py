def li():
    return list(map(int, input().split()))


if __name__ == "__main__":
    n = int(input())
    [ga, sa, ba] = li()
    [gb, sb, bb] = li()

    # A->Bでのトレード成果
    # ga, sa, baの中で最大効率を探して、割り切れる範囲で先に進めてしまう
    # gaが最大効率なら(n//ga - 1)*gaまではgを買ったことにすればいい
    # r_g = gb / ga
    # r_s = sb / sa
    # r_b = bb / ba
    # if (n // ga - 5000) > 0 and r_g >= 1 and r_g >= r_s and r_g >= r_b:
    #     skip = (n // ga - 5000) * ga
    #     dp = [gb * skip] * (n + 1 - skip)
    # elif (n // sa - 5000) > 0 and r_s >= 1 and r_s >= r_g and r_s >= r_b:
    #     skip = (n // sa - 5000) * sa
    #     dp = [sb * skip] * (n + 1 - skip)
    # elif (n // ba - 5000) > 0 and r_b >= 1 and r_b >= r_g and r_b >= r_s:
    #     skip = (n // ba - 5000) * ba
    #     dp = [bb * skip] * (n + 1 - skip)
    # else:
    #     skip = n - 1
    #     dp = [n - 1] * 2
    dp = [0] * (n + 1)

    for i in range(1, len(dp)):
        g_trade = dp[i - ga] + gb if i - ga >= 0 else dp[i - 1]
        s_trade = dp[i - sa] + sb if i - sa >= 0 else dp[i - 1]
        b_trade = dp[i - ba] + bb if i - ba >= 0 else dp[i - 1]
        dp[i] = max(dp[i - 1] + 1, g_trade, s_trade, b_trade)
    # print(dp)
    a_result = dp[-1]

    # B->Aでのトレード成果
    # r_g = ga / gb
    # r_s = sa / sb
    # r_b = ba / bb
    # skip_num = 5000
    # if (a_result // gb - 1) > 0 and r_g >= 1 and r_g >= r_s and r_g >= r_b:
    #     skip_num = max(sb // gb + 1, bb // gb + 1)*2
    #     skip = max((a_result // gb - skip_num), 0) * gb
    #     dp = [ga * skip] * (a_result + 1 - skip)
    # elif (a_result // sb - 1) > 0 and r_s >= 1 and r_s >= r_g and r_s >= r_b:
    #     skip_num = max(gb // sb + 1, bb // sb + 1)*2
    #     skip = max((a_result // sb - skip_num), 0) * sb
    #     dp = [sa * skip] * (a_result + 1 - skip)
    # elif (a_result // bb - 1) > 0 and r_b >= 1 and r_b >= r_g and r_b >= r_s:
    #     skip_num = max(sb // bb + 1, gb // bb + 1)*2
    #     skip = max((a_result // bb - skip_num), 0) * bb
    #     dp = [ba * skip] * (a_result + 1 - skip)
    # else:
    #     skip = a_result - 1
    #     dp = [a_result - 1] * 2
    dp = [0] * (a_result + 1)

    for i in range(1, len(dp)):
        g_trade = dp[i - gb] + ga if i - gb >= 0 else dp[i - 1]
        s_trade = dp[i - sb] + sa if i - sb >= 0 else dp[i - 1]
        b_trade = dp[i - bb] + ba if i - bb >= 0 else dp[i - 1]
        dp[i] = max(dp[i - 1] + 1, g_trade, s_trade, b_trade)
    # print(dp)
    print(dp[-1])

# n+1個のドングリを取引にかけたときに得られるドングリポテンシャルは
# n個までの最適+1, n-gA個までの最適+gB, n-sA個までの最適+sB, n-bA個までの最適+bBで一番大きくなる値

# AでBより安く金属を手に入れる
# Bでドングリに戻して、Aより安く金属を手に入れる
# Aでドングリに戻して帰る
