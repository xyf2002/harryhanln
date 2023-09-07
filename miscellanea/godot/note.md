# Note on Godot game engine

## GDScript

GDScript is dynamically typed. It is a duckable language.

By duckable, it means that an object can be invoked with a method if such method exists for this object, not necessarily for the class.

```GDScript
func _on_object_hit(object):
    if object.has_method("smash"):
        object.smash()
```

## Export annotation

Class member (value of varaible belongs to the class) can be exported.
```
@export var number: int = 5
```

By exporting, the variable will be saved into the scene and would be able to be edited graphically.


