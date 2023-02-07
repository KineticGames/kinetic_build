# kinetic_build

## build commands
each build subcommand is it's own program. e.g. `kinetic new [options]` becomes `kinetic_new [options]`

## Project file format

`<project_name>.kbp`:
```
name: "<project_name>"
c_version: <version_number>
version: <major>.<minor>.<patch>
dependencies: [
	{
		name: "<dependency_name>"
		version: <major>.<minor>.<patch>
		options: [
			<build_option>: <option_value>
		]
		repository: "<repository_link>"
	}
]
```
