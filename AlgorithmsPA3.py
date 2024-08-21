#Aryan Chhabra
import json
import sys

def read_json_file(input_file):
    with open(input_file, 'r') as file:
        data = json.load(file)

    return data


def traverse_json(node, level, result):
    if node is None:
        return

    if level != 0:
        result.append([level, node.get("field1"), node.get("field2")])

    if node.get("nodes") and isinstance(node["nodes"], list):
        for child in node["nodes"]:
            traverse_json(child, level + 1, result)


def write_csv_file(output_file, data):
    with open(output_file, 'w') as file:
        for node in data:
            file.write(','.join(map(str, node))+'\n')


def main():
    if len(sys.argv) != 3:
        print("Usage: python pa3.py input.json output.csv")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    json_data = read_json_file(input_file)
    result = []
    traverse_json(json_data, 0, result)
    write_csv_file(output_file, result)


main()