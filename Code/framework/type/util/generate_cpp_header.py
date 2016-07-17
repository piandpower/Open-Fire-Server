from enum import Enum
from framework.type import Request
from stringcase import pascalcase


def generate_cpp_header(python_enum: Enum):
    name = python_enum.__name__
    with open(name + '.h', 'w') as f:
        f.write('#pragma once\n')
        f.write('\n')
        f.write('enum class ' + name + '\n')
        f.write('{')
        enum_strings = []
        for element in python_enum:
            enum_strings.append('\n	' + pascalcase(element.name) + ' = ' + str(element.value))
        f.write(','.join(enum_strings))
        f.write('\n};\n')

if __name__ == "__main__":
    generate_cpp_header(Request)
