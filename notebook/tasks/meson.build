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
all_sources = ['runner.c'] + tasks_cards.stdout().strip().split('\n')

# Filter only supported extensions (.c, .cpp, .m, .mm)
tasks_source = []
foreach f : all_sources
    ext = f.split('.')[-1]
    if ext == 'c' or ext == 'cpp' or ext == 'm' or ext == 'mm'
        tasks_source += [f]
    endif
endforeach

# Create a single executable with all sources
challenge = executable(
    'notebook',
    tasks_source,
    dependencies: [dependency('fossil-test')]
)

# Add test
test('tasks test cases', challenge)