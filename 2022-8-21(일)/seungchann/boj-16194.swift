import Foundation

func solve(n: Int, prices: [Int]) {
    let INF = 2147483647
    var dp = [Int](repeating: INF, count: n+1)
    dp[0] = 0
    dp[1] = prices[0]
    for idx in (2...n) {
        for (i, price) in prices.enumerated() {
                if idx-(i+1) >= 0 {
                    dp[idx] = min(dp[idx], dp[idx-(i+1)] + price)
                }
            }
        }
    print(dp[n])
}

func main() {
    let n = Int(readLine()!)!
    let arr = readLine()!.split(separator: " ").map{ Int(String($0))! }

    solve(n: n, prices: arr)
}

main()