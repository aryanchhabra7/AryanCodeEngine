import csv
import sys

def knapsack(weights, values, capacity):
    n = len(weights)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]

    max_value = dp[n][capacity]

    # Backtrack to find the items selected
    selected_weights = []
    w = capacity
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:
            selected_weights.append(weights[i - 1])
            w -= weights[i - 1]

    return max_value, selected_weights

def main():
    if len(sys.argv) != 3:
        print("Usage: python pa2.py <csv_filename> <cart_capacity>")
        sys.exit(1)

    csv_filename = sys.argv[1]
    cart_capacity = int(sys.argv[2])

    weights = []
    values = []

    try:
        with open(csv_filename, 'r') as file:
            reader = csv.reader(file)
            for row in reader:
                vals = list(map(int, row))
                weights.append(int(vals[0]))
                values.append(int(vals[1]))
    except FileNotFoundError:
        print(f"Error: File '{csv_filename}' not found.")
        sys.exit(1)

    max_value, selected_weights = knapsack(weights, values, cart_capacity)

    print(f"Max value of items taken is {max_value}.", end = " ")
    print(f"Array of weights of items taken is {selected_weights}")


main()
