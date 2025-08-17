Get-ChildItem -Path $source -Recurse -Directory | ForEach-Object {
    $cpp = Get-ChildItem -Path $_.FullName -Filter "*.cpp" -ErrorAction SilentlyContinue
    $md  = Get-ChildItem -Path $_.FullName -Filter "WIP" -ErrorAction SilentlyContinue

    if ($cpp -and $md) {
        # Build a unique name from the folder path
        $relativePath = $_.FullName.Substring($source.Length).Trim("\")
        $safeName = $relativePath -replace "[\\/]", "_"  # Convert path separators to underscores

        # Copy and rename files
        Copy-Item $cpp.FullName -Destination (Join-Path $target "$safeName.cpp") -Force
        Copy-Item $md.FullName  -Destination (Join-Path $target "$safeName.md") -Force
    }
}
