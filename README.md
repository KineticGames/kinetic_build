# kinetic_build

## Local files
In `~/.kinetic` all the programs are stored: 
- `.kinetic`
  - `actions`
    - contains the executable that get executed when an action is called
  - `dependencies`
    - stores the URLs and latest known versions of dependencies

## Build Commands
Each build subcommand is its own program. e.g. `kinetic new [options]` becomes `kinetic_new [options]`

## Kinetic Project file format

`<project_name>.kp`:
```
name: "<project_name>"
c_version: <version_number> # defaults to 11
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
