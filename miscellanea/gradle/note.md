# Gradle Note

To ensure build consistency and reduce dependency on system-specific applications, all gradle project shall be run with gradle wrapper `./gradlew`, which is an executable present in the root directory.

## Overview

Gradle is organized into build, which contiain root project, which contains subprojects.

build is configured by `setting.gradle.kts` in the root directory. 
Each project is configured by `build.gradle.kts` in their sub directory.

## Quick commands

Gradle tasks can build, run, or test the projects.

In root directory:

- `./gradlew tasks` list all tasks
- `./gradlew :app:tasks` list all task for app project
- `./gradlew run` run the project 
- `./gradlew test` run the test 

