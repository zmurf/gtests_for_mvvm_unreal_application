#!/usr/bin/python3

import pathlib, subprocess, typing, os, sys

# Defaults
kDefaultProject: str = "cmake_gtest"
kDefaultTarget: str = "Linux"
kDefaultBuildProfile: str = "Development"

kRepositoryPath = pathlib.Path(__file__).resolve().parent.parent
kBuildOutputPath = kRepositoryPath.joinpath("output")
kStageOutputPath = kRepositoryPath.joinpath("staged")
kUnrealEnginePath = kRepositoryPath.parent.joinpath(f"epic/unreal-engine")
kBuildScriptPath = kUnrealEnginePath.joinpath(f"Engine/Build/BatchFiles/RunUAT.sh")

kEnvironmentVariables: typing.Dict[str, str] = {
}
kValidBuildProfiles: typing.List[str] = {"Development", "Shipping"}
kValidTargets: typing.List[str] = {"Linux", "QNX"}

kBuildFlags: typing.List[str] = [
    f"allmaps",  # Include all maps
    f"cook",  # Cook project
    f"build",  # Build project
    f"package",  # Package the project
    f"stage",  # Put build in a stage directory
    f"pak",  # Create pak-file(s)
    f"archive",  # Put build in a archive directory
    f"nop4",  # Disable perforce
    f"prereqs",  # Stage prerequisites along with the project
]


def build(project: str, target: str = "Linux", build_profile: str = "Development"):
    # Validate project
    valid_projects = [x.parent.name for x in kRepositoryPath.rglob("*.uproject")]
    assert project in valid_projects, f'Available projects: {", ".join(valid_projects)}!'
    project_file = next(kRepositoryPath.joinpath(project).rglob("*.uproject"))

    # Validate target
    assert target in kValidTargets, f'Available targets: {", ".join(kValidTargets)}'

    # Validate build profile
    # build_profile = build_profile.capitalize()
    assert build_profile in kValidBuildProfiles, f'Available build profiles: {", ".join(kValidBuildProfiles)}'

    kBuildFlags.append(f"clientconfig={build_profile}")
    kBuildFlags.append(f"configuration={build_profile}")
    kBuildFlags.append(f"Platform={target}")
    kBuildFlags.append(f"targetplatform={target}")
    kBuildFlags.append(f"project={project_file.as_posix()}")
    kBuildFlags.append(f'archivedirectory="{kBuildOutputPath.as_posix()}"')  # Where to put the archived files

    if build_profile == "Shipping":
        kBuildFlags.append(f"SkipCookingEditorContent")  # Don't include the content from Editor
        kBuildFlags.append(f"AdditionalCookerOptions=-nodev")  # Extra args to the cooking step, no developer content

    # Execute the command
    build_environment = os.environ.copy()
    build_environment = {**build_environment, **kEnvironmentVariables}
    arguments = [f"-{x}" for x in kBuildFlags]
    command = f'{kBuildScriptPath.as_posix()} BuildCookRun {" ".join(arguments)}'

    print(f'Running command "{command}"', flush=True)
    execution = subprocess.Popen(
        command,
        shell=True,
        cwd=kRepositoryPath.as_posix(),
        env=build_environment,
        stdout=sys.stdout,
        stderr=subprocess.STDOUT,
    )
    execution.wait()


# Parse each argument since Fire was not available in CI docker machine...
def get_argument_value(arguments: typing.List[str], index: int, default: str) -> str:
    return arguments[index] if index < len(arguments) else default


# Trigger the build
if __name__ == "__main__":
    passed_arguments = sys.argv[1:]
    build(
        get_argument_value(passed_arguments, 0, kDefaultProject),
        get_argument_value(passed_arguments, 1, kDefaultTarget),
        get_argument_value(passed_arguments, 2, kDefaultBuildProfile),
    )
