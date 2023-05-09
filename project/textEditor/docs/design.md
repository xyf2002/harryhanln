# The design of the Editor

## Reading from Files

There shall be text buffer, storing the openned file. Many files may be openned at the same time, each with their correspounding buffer.

The buffer shall be stored in memory and in a cached filed. The cached file is constantly written into as a mean of crash migitation.


