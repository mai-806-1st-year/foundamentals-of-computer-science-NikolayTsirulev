import os
import argparse

def write_files_with_suffix(directory, suffix, output_file, max_size):
    with open(output_file, 'w') as f:
        for filename in os.listdir(directory):
            if filename.endswith(suffix):
                filepath = os.path.join(directory, filename)
                size = os.stat(filepath).st_size
                if size <= max_size:
                    f.write(f"{filename} {size}\n")

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('directory', help='directory to search for files')
    parser.add_argument('suffix', help='file suffix to search for')
    parser.add_argument('output_file', help='file to write results to')
    parser.add_argument('max_size', type=int, help='maximum file size in bytes')
    args = parser.parse_args()

    write_files_with_suffix(args.directory, args.suffix, args.output_file, args.max_size)
