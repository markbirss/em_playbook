local touch = load_int("about", "page")
if touch > 0 then
    touch = touch - 1
end
smart_draw_r("/about/root.bin", 600, 2400, 0, 800 * (2 - touch), 600, 800, 0, 0, 0)