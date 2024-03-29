# arduino-environment-sensor

# Create New Project

Only needed when creating new project, not when setting up an existing one.

Run `arduino-cli sketch new <projectName>` in root of new project's git repo.

# Seup Dev Environment

## Get Board Info

- List devices with `arduino-cli board list`.
- Note the value of the bellow columns for the board you'll use (they'll be used later:
   - `Port`
   - `FQBM` (Fully Qualified Board Name)
   - `Core`

## Download Core

Install core with `arduino-cli core install <core>`.

## Install Library(ies)

Install libraries needed by the project with `arduino-cli lib install <libraryName>`. If not sure what library(ies) are needed, [compile the project](#compile-project) and use the error to determine what additional library(ies) are needed.

## Compile Project

- Navigate into project's directory.
- Run `arduino-cli compile -b <fqbm>`

## Upload Project to Board

Ensure your user is a member of the `dialout` group, then run `arduino-cli upload -b <fqbm> -p <port>`.

