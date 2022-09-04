/**
boj-14728.swift
https://www.acmicpc.net/problem/14728
*/

func solve(_ n: Int, _ t: Int, _ time: [Int], _ score: [Int]) -> Int {
    var dp: [[Int]] = Array(repeating: Array(repeating: 0, count: t+1), count: n+1)

    for i in 1...n {
        for j in 1...t {
            if (j - time[i] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-time[i]] + score[i])
            } else {
                dp[i][j] = dp[i-1][j]
            }
        }
    }

    return dp[n][t]
}

func main() {
    let NT = readLine()!.split(separator: " ").map { Int(String($0))! }
    let N = NT[0], T = NT[1]
    var time: [Int] = [0]
    var score: [Int] = [0]

    for _ in 1...N {
        let splited = readLine()!.split(separator: " ").map { Int(String($0))! }
        time.append(splited[0])
        score.append(splited[1])
    }

    print(solve(N, T, time, score))
}

main()