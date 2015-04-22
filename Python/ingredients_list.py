from collections import Counter, defaultdict
__author__ = 'jimblackler'


def solve_1(lines):
  remain = {}
  for line in lines:
    if ':' in line:
      ingredient, dependencies = line.split(':')
      remain[ingredient] = dependencies.split(",")
    else:
      remain[line] = []

  output = []
  while remain:
    next_remain = {}
    for ingredient, dependencies in remain.iteritems():
      if all(dependency in output
             for dependency in dependencies):
        output.append(ingredient)
      else:
        next_remain[ingredient] = dependencies
    if remain == next_remain:
      break
    remain = next_remain

  return output


def solve_2(lines):
  without_dependencies = []
  reverse_dependencies = defaultdict(set)
  number_dependencies = {}
  for line in lines:
    if ':' in line:
      ingredient, dependencies = line.split(':')
      split_dependencies = dependencies.split(",")
      for dependency in split_dependencies:
        reverse_dependencies[dependency].add(ingredient)
      number_dependencies[ingredient] = \
          len(split_dependencies)
    else:
      without_dependencies.append(line)

  output = []

  def add_ingredient(ingredient):
    output.append(ingredient)
    for dependency in reverse_dependencies[ingredient]:
      number_dependencies[dependency] -= 1
      if number_dependencies[dependency] == 0:
        add_ingredient(dependency)

  for ingredient in without_dependencies:
    add_ingredient(ingredient)

  return output


def solve(lines):
  print solve_1(lines)
  print solve_2(lines)


solve([
  'baking powder:cocoa',
  'bicarbonate of soda:baking powder',
  'cocoa:flour,sugar',
  'eggs:bicarbonate of soda,baking powder',
  'flour',
  'milk:eggs',
  'sugar:flour',
  'vanilla extract:eggs',
  'vegetable oil:eggs',
  'water:milk,vegetable oil,vanilla extract'])

solve([
  'e:m',
  'f',
  'g',
  'm:p',
  'p:e',
  's:f',
  'w:s,g'])