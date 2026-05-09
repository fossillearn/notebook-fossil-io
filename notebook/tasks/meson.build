# Run wildcard.py to collect test source files
tasks_cards = run_command(
    ['python3', '..' / 'tools' / 'wildcard.py'],
    check: true
)

# Run runner.py (if needed)
run_command(
    ['python3', '..' / 'tools' / 'runner.py'],
    check: true
)

# Split stdout into a list of filenames and include main.c
all_sources = ['runner.c'] + tasks_cards.stdout().strip().split()

# Create a single executable with all sources
challenge = executable(
    'notebook',
    all_sources,
    include_directories: include_directories('.'),
    dependencies: [dependency('fossil-test'), dependency('fossil-io')]
)

# Add test
test('tasks test cases', challenge)