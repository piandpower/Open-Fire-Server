<?php

use Illuminate\Database\Seeder;

use App\StrongPoint;

class StrongPointSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        /*
         * TODO
         * 1. Create Start Node
         * 2. Multiplication Childe Nodes
         * 3. Create relation edges
         */

        $strongPoint = new StrongPoint;
        $strongPoint->location_x = 10;
        $strongPoint->location_y = 20;
        $strongPoint->save();
    }
}
